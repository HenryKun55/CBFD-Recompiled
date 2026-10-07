export const meta = {
  name: 'conker-match',
  description: 'Strict-matching decompilation of Conker functions: one agent per function, verified with match_func.py',
  phases: [{ title: 'Match', detail: 'one agent per function iterates C until IDO output equals the ROM' }],
}

const REPO = '/Users/flaviohenriquedonascimentoandrade/Documents/workspace/games/cbfd/CBFD-Recompiled'
const SCHEMA = {
  type: 'object',
  properties: {
    func: { type: 'string' },
    status: { type: 'string', enum: ['match', 'nonmatch', 'handwritten', 'error'] },
    words_differ: { type: 'integer' },
    total_words: { type: 'integer' },
    attempts: { type: 'integer' },
    candidate_path: { type: 'string' },
    header_change: { type: 'string' },
    notes: { type: 'string' },
  },
  required: ['func', 'status', 'words_differ', 'attempts', 'candidate_path', 'notes'],
}

function prompt(f, file) {
  return `You are doing strict MATCHING decompilation of one function of Conker's Bad Fur Day (N64, compiled with IDO 5.3): C source that IDO compiles to exactly the ROM's instructions.

Function: ${f}. Its #pragma GLOBAL_ASM is in ${REPO}/conker/conker/src/${file}.c; the target assembly is conker/conker/asm/nonmatchings/${file}/${f}.s (comments hold the ROM's words). Read the source file (neighbouring decompiled functions show the types and structs in use; comments may record earlier attempts) and conker/conker/include (structs.h, variables.h, functions.h).

Checker (IDO and MIPS binutils only exist in the Docker container):
  docker exec conker-match python3 match_func.py ${f} build/cand/${f}.c --diff
(conker-match is a running container, native arm64, working directory conker/conker of ${REPO}; each check takes about a second)
It prints MATCH or "N of M words differ" with a side-by-side listing (left = ROM, right = your compile, !! = differing). It also checks that every call/data reference names the same symbol as the ROM ("wrong symbol at ...") and that switch jump tables send each case to the same place ("jump table differs ..."). Without the candidate argument it compiles m2c's draft; add --m2c-out build/cand/${f}.m2c.c to save the draft as a starting point.
How it builds your candidate: the source file with your candidate replacing ${f}'s pragma in place (file scope, so you may put extern declarations, prototypes or a uniquely named struct (struct ${f}_s) before the function) and all other pragmas removed, compiled with that file's flags (usually -O2 -g3 -mips2).

Rules:
- Write ONLY build/cand/${f}.c (in conker/conker). Never edit src/, include/, the Makefile or anything else: hundreds of agents work in parallel.
- The candidate is the function definition plus any file-scope declarations it needs. No #pragma lines, no extra dummy functions, and never invent symbol names (e.g. func_X_u8 or renamed externs) to dodge a declaration: the checker rejects them and they wouldn't link.
- If the function only matches with a different prototype than include/functions.h or the file declares (e.g. a parameter is u8, not s32), don't fight it with casts: note the exact prototype in header_change and leave the candidate written the natural way (it will fail to compile against the old prototype or differ; that's fine, report it).
- Matching levers: variable types and signedness, declaration order of locals, expression order and grouping, temporaries vs inline expressions, loop forms, if/else shape, early returns, pointer vs array indexing, casts, struct field types, switch case order (write cases in the order the code lays them out). Register differences usually mean ordering; extra/missing instructions usually mean types or temporaries.
- Stop when it matches, or after about 40 compiles without progress, keeping the file at your best result (fewest differing words). If the assembly is clearly handwritten (instructions IDO never emits, e.g. addi, odd float registers, 'handwritten' comments), stop early with status handwritten.
- Run the checker on your final file and report exactly what it printed. Never claim MATCH it didn't print.

Return func, status, words_differ (0 for match), total_words, attempts (compiles run), candidate_path (build/cand/${f}.c), header_change (the prototype it needs, or empty), notes (one or two sentences: what made it match, or what still differs).`
}

phase('Match')
let done = 0, matched = 0
const results = await pipeline(args, item =>
  agent(prompt(item[0], item[1]), { label: item[0], phase: 'Match', schema: SCHEMA }).then(r => {
    done++
    if (r && r.status === 'match') matched++
    if (done % 50 === 0) log(`${done}/${args.length} done, ${matched} matched`)
    return r
  }))
const ok = results.filter(Boolean)
log(`${ok.filter(r => r.status === 'match').length}/${args.length} matched`)
return {
  matched: ok.filter(r => r.status === 'match').map(r => r.func),
  header_changes: ok.filter(r => r.header_change).map(r => ({ func: r.func, change: r.header_change })),
  results: ok.map(r => ({ func: r.func, status: r.status, words_differ: r.words_differ, total_words: r.total_words, attempts: r.attempts })),
}
