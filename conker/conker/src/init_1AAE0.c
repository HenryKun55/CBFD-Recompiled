#include <n_libaudio.h>
#include "functions.h"
#include "variables.h"

void __n_resetPerfChanState();

void func_1001AAE0(N_ALSeqPlayer *seqp, N_ALVoice *voice) {
    N_ALVoiceState *prev = 0;
    N_ALVoiceState *vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if (&vs->voice == voice) {
            if (prev) {
                prev->next = vs->next;
            } else {
                seqp->vAllocHead = vs->next;
            }
            if (vs == seqp->vAllocTail) {
                seqp->vAllocTail = prev;
            }
            vs->next = seqp->vFreeList;
            seqp->vFreeList = vs;
            seqp->usedVoices--;
            return;
        }
        prev = vs;
    }
}
// void func_1001AAE0(void *arg0, s32 arg1) {
//     void *sp4;
//     void *sp0;
//     void *temp_t6;
//
//     sp4 = NULL;
//     sp0 = arg0->unk64;
//     if (sp0 != 0) {
// loop_1:
//         if ((sp0 + 4) == arg1) {
//             if (sp4 != 0) {
//                 *sp4 = (s32) *sp0;
//             } else {
//                 arg0->unk64 = (void *) *sp0;
//             }
//             if (arg0->unk68 == sp0) {
//                 arg0->unk68 = sp4;
//             }
//             *sp0 = (void *) arg0->unk6C;
//             arg0->unk6C = sp0;
//             arg0->unk8D = (u8) (arg0->unk8D - 1);
//             return;
//         }
//         sp4 = sp0;
//         temp_t6 = *sp0;
//         sp0 = temp_t6;
//         if (temp_t6 != 0) {
//             goto loop_1;
//         }
//     }
// }

void __n_seqpReleaseVoice(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime deltaTime) {
    N_ALEvent evt;
    N_ALVoiceState *vs = (N_ALVoiceState *)voice->unk10;

    if (vs->envPhase == AL_PHASE_ATTACK) {
        ALLink *thisNode;
        ALLink *nextNode;
        N_ALEventListItem *thisItem, *nextItem;

        thisNode = seqp->evtq.allocList.next;
        while (thisNode != 0) {
            nextNode = thisNode->next;
            thisItem = (N_ALEventListItem *)thisNode;
            nextItem = (N_ALEventListItem *)nextNode;
            if (thisItem->evt.type == AL_SEQP_ENV_EVT) {
                if (thisItem->evt.msg.vol.voice == voice) {
                    if (nextItem)
                        nextItem->delta += thisItem->delta;
                    {
                        ALLink *_ln = thisNode;
                        if (_ln->next)
                            _ln->next->prev = _ln->prev;
                        if (_ln->prev)
                            _ln->prev->next = _ln->next;
                    }
                    {
                        ALLink *_ln = thisNode;
                        ALLink *_to = &seqp->evtq.freeList;
                        _ln->next = _to->next;
                        _ln->prev = _to;
                        if (_to->next)
                            _to->next->prev = _ln;
                        _to->next = _ln;
                    }
                }
            }
            thisNode = nextNode;
        }
    }

    vs->velocity = 0;
    vs->envPhase = AL_PHASE_RELEASE;
    vs->envGain = 0;
    vs->envEndTime = seqp->curTime + deltaTime;

    n_alSynSetPriority(voice, 0);
    n_alSynSetVol(voice, 0, deltaTime);
    evt.type = AL_NOTE_END_EVT;
    evt.msg.note.voice = voice;
    deltaTime += AL_USEC_PER_FRAME * 2;
    n_alEvtqPostEvent(&seqp->evtq, &evt, deltaTime, 0);
}
// void __n_seqpReleaseVoice(void *arg0, void *arg1, s32 arg2) {
//     void *sp3C;
//     s16 sp38;
//     void *sp34;
//     void *sp30;
//     void *sp2C;
//     void *sp28;
//     void *sp24;
//     void *sp20;
//     void *sp1C;
//     void *sp18;
//
//     sp34 = arg1->unk10;
//     if (sp34->unk38 == 0) {
//         sp30 = arg0->unk50;
//         if (sp30 != 0) {
// loop_2:
//             sp2C = *sp30;
//             sp28 = sp30;
//             sp24 = sp2C;
//             if ((sp28->unkC == 6) && (sp28->unk10 == arg1)) {
//                 if (sp24 != 0) {
//                     sp24->unk8 = (s32) (sp24->unk8 + sp28->unk8);
//                 }
//                 sp20 = sp30;
//                 if (sp20->unk0 != 0) {
//                     sp20->unk0->unk4 = (s32) sp20->unk4;
//                 }
//                 if (sp20->unk4 != 0) {
//                     *sp20->unk4 = (s32) sp20->unk0;
//                 }
//                 sp1C = sp30;
//                 sp18 = arg0 + 0x48;
//                 sp1C->unk0 = (s32) *sp18;
//                 sp1C->unk4 = sp18;
//                 if (*sp18 != 0) {
//                     (*sp18)->unk4 = sp1C;
//                 }
//                 *sp18 = sp1C;
//             }
//             sp30 = sp2C;
//             if (sp30 != 0) {
//                 goto loop_2;
//             }
//         }
//     }
//     sp34->unk37 = (u8)0;
//     sp34->unk38 = (u8)3;
//     sp34->unk34 = (u8)0;
//     sp34->unk28 = (s32) (arg0->unk1C + arg2);
//     n_alSynSetPriority(arg1, 0);
//     n_alSynSetVol(arg1, 0, arg2);
//     sp38 = 5;
//     sp3C = arg1;
//     arg2 = arg2 + 0x7D00;
//     n_alEvtqPostEvent(arg0 + 0x48, &sp38, arg2, 0);
// }

u8 func_1001ADA4(N_ALSeqPlayer *seqp, N_ALVoice *voice, ALMicroTime time) {
    ALLink *thisNode;
    ALLink *nextNode;
    N_ALEventListItem *thisItem;
    ALMicroTime itemTime = 0;
    u8 ret = 1;

    thisNode = seqp->evtq.allocList.next;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        thisItem = (N_ALEventListItem *)thisNode;
        itemTime += thisItem->delta;
        if (thisItem->evt.type == 5) {
        if (thisItem->evt.msg.note.voice == voice) {
            if (itemTime > time) {
                if (nextNode != 0) {
                    ((N_ALEventListItem *)nextNode)->delta += thisItem->delta;
                }
                {
                    ALLink *ln = thisNode;
                    if (ln->next) {
                        ln->next->prev = ln->prev;
                    }
                    if (ln->prev) {
                        ln->prev->next = ln->next;
                    }
                }
                {
                    ALLink *element = thisNode;
                    ALLink *after = &seqp->evtq.freeList;
                    element->next = after->next;
                    element->prev = after;
                    if (after->next) {
                        after->next->prev = element;
                    }
                    after->next = element;
                }
            } else {
                ret = 0;
            }
            break;
        }
        }
        thisNode = nextNode;
    }
    return ret;
}

N_ALVoiceState *__n_mapVoice(N_ALSeqPlayer *seqp, u8 key, u8 vel, u8 channel)
{
    N_ALVoiceState  *vs = seqp->vFreeList;

    if (seqp->usedVoices > seqp->maxVoices) {
        return NULL;
    }

    if (vs) {

        seqp->vFreeList = vs->next;

        vs->next = 0;

        if (!seqp->vAllocHead)
            seqp->vAllocHead = vs;
        else
            seqp->vAllocTail->next = vs;

        seqp->vAllocTail = vs;

        vs->channel             = channel;
        vs->key                 = key;
        vs->velocity            = vel;
        vs->voice.unk10         = vs; // this isn't right

        seqp->usedVoices++;
    }

    return vs;
}

N_ALVoiceState *func_1001AFEC(N_ALSeqPlayer *seqp, u8 key, u8 channel)
{
    N_ALVoiceState  *vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if ((vs->key == key) && (vs->channel == channel) &&
            (vs->phase != AL_PHASE_RELEASE) && (vs->phase != AL_PHASE_SUSTREL))
            return vs;
    }

    return 0;
}

ALSound *func_1001B07C(N_ALSeqPlayer *seqp, u8 key, u8 vel, u8 chan)
{
    ALInstrument *inst = seqp->chanState[chan].instrument;
    s32 l = 1;
    s32 r;
    s32 i;
    ALKeyMap *keymap;

    if (inst == 0) {
        return 0;
    }
    r = inst->soundCount;

    while (r >= l) {
        i = (l+r)/2;
        keymap = inst->soundArray[i-1]->keyMap;
        if ((key >= keymap->keyMin) && (key <= keymap->keyMax) &&
            (vel >= keymap->velocityMin) && (vel <= keymap->velocityMax)) {
            return inst->soundArray[i-1];
        } else if ((key < keymap->keyMin) ||
                   ((vel < keymap->velocityMin) && (key <= keymap->keyMax))) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }
    return 0;
}

s16 __n_vsVol(N_ALVoiceState *vs, N_ALSeqPlayer *seqp)
{
    u32     t1,t2;

    t1 = (vs->tremelo*vs->velocity*vs->envGain) >> 6;
    t2 = (vs->sound->sampleVolume*seqp->vol*
          seqp->chanState[vs->channel].vol) >> 14;

    if (seqp->chanState[vs->channel].unkD != 0xFF) {
        t2 = ((seqp->chanState[vs->channel].unkD * t2) + 1) >> 8;
    }

    t1 *= t2;
    t1 >>= 15;

    return t1;
}

s32 func_1001B310(struct25 *arg0, struct26 *arg1) {
    s32 sp14;
    s32 sp10;

    sp14 = arg1->unk60[arg0->unk35].unkA & 0x80;
    sp10 = ((arg1->unk60[arg0->unk35].unkA & 0x7F) + (s32) (arg1->unk7C * 127.0f)) * arg1->unk80;

    return (MAX(0, MIN(127, sp10)) | sp14) & 0xff;
}
// NON-MATCHING: missing a move
// s32 func_1001B310(struct25 *arg0, struct26 *arg1) {
//     s32 sp14;
//     s32 sp10;
//
//     sp14 = arg1->unk60[arg0->unk35].unkA & 0x80;
//     sp10 = ((arg1->unk60[arg0->unk35].unkA & 0x7F) + (s32) (arg1->unk7C * 127.0f)) * arg1->unk80;
//
//     return (MAX(0, MIN(127, sp10)) | sp14) & 0xff;
// }

ALMicroTime __n_vsDelta(N_ALVoiceState *vs, ALMicroTime t) {
  /*
   * If we are interrupting a previously set envelope segment, we
   * need to recalculate the segment end time given the current
   * time. Note: this routine assumes that the voice is currently
   * playing.
   */

  s32 delta = vs->envEndTime - t;

  if (delta >= 0) {
      return delta;
  } else {
      return AL_GAIN_CHANGE_TIME;
  }
}

ALPan __n_vsPan(N_ALVoiceState *vs, N_ALSeqPlayer *seqp)
{
    s32 tmp;

    tmp = seqp->chanState[vs->channel].pan - AL_PAN_CENTER +
        vs->sound->samplePan;
    tmp = MAX(tmp, AL_PAN_LEFT);
    tmp = MIN(tmp, AL_PAN_RIGHT);

    return (ALPan) tmp;
}

// not vanilla
void __n_initFromBank(N_ALSeqPlayer *seqp, ALBank *b)
{
    s32 i;
    ALInstrument *inst = 0;

    for (i = 1; !inst; i++)
        inst = b->instArray[i];

    for (i = 0; i < seqp->maxChannels; i++)
        __n_resetPerfChanState(seqp, i);

    if (b->percussion)
        __n_resetPerfChanState(seqp, i);
}

void __n_initChanState(N_ALSeqPlayer *seqp)
{
    int i;

    for (i = 0; i < seqp->maxChannels; i++)
    {
        seqp->chanState[i].instrument = 0;
        __n_resetPerfChanState (seqp, i);
    }
}

void __n_resetPerfChanState(N_ALSeqPlayer *seqp, s32 chan) {
    seqp->chanState[chan].fxmix = 0;
    seqp->chanState[chan].pan = AL_PAN_CENTER;
    seqp->chanState[chan].vol = AL_VOL_FULL;
    seqp->chanState[chan].priority = AL_DEFAULT_PRIORITY;
    seqp->chanState[chan].sustain = 0;
    seqp->chanState[chan].bendRange = 200;
    seqp->chanState[chan].pitchBend = 1.0f;
    seqp->chanState[chan].unk17 = 0;
    seqp->chanState[chan].unkD = 255;
    seqp->chanState[chan].unkE = 255;
    seqp->chanState[chan].unkF = 0;
    seqp->chanState[chan].unkB = 0;
    seqp->chanState[chan].unk16 = 0;
    seqp->chanState[chan].unk15 = 0;
    seqp->chanState[chan].unk14 = 0;
    seqp->chanState[chan].unk8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/init_1AAE0/func_1001B7D0.s")
s32 func_1001BD34(void *arg0, s32 *arg1, s32 arg2) {
    s32 (*sp1C)(s32, s32);
    s32 sp18;

    sp18 = 0;
    sp1C = (*(s32 (*(**)(void))(s32, s32))((char *)arg0 + 0x28))();
    if (sp1C != NULL) {
        if (arg2 == -1) {
            sp18 = sp1C((s32)arg1, 1);
        } else {
            sp18 = sp1C(*arg1 + arg2 * 4 + 0x10, 0);
        }
        if ((sp18 != 0) && ((sp18 & 0xFF000003) != 0x80000000)) {
            return 0;
        }
    } else {
        return 0;
    }
    return sp18;
}
// s32 func_1001BD34(void *arg0, void *arg1, s32 arg2) {
//     void *sp1C;
//     s32 sp18;
//     s32 phi_v0;
//
//     sp18 = 0;
//     sp1C = arg0->unk28();
//     if (sp1C == 0) {
//         return 0;
//     }
//     if (arg2 == -1) {
//         phi_v0 = sp1C(arg1, 1);
//     } else {
//         phi_v0 = sp1C(*arg1 + (arg2 * 4) + 0x10, 0);
//     }
//     sp18 = phi_v0;
//     if ((sp18 != 0) && ((sp18 & 0xFF000003) != 0x80000000)) {
//         return 0;
//     }
//     return sp18;
// }

// Calls a callback: the function pointer at 0x30 of `handler`, with either `data`
// itself (index == -1) or the index-th word of an array at 0x10 in `data`. Its
// one caller, _n_handleEvent, passes D_8002BA2C->unk38 as the handler and a
// sound's unk3C->unkC and (s16) unk4C as data and index (func_10017100 sets those
// two fields when it allocates the sound).
void func_1001BE1C(void *handler, s32 data, s32 index) {
    if (index == -1) {
        (*(s32 (**)(s32))((char *)(handler) + 0x30))(data);
    } else {
        (*(s32 (**)(s32))((char *)(handler) + 0x30))(((s32 *)((char *)data + 0x10))[index]);
    }
}

void __n_seqpStopOsc(N_ALSeqPlayer *seqp, N_ALVoiceState *vs)
{
    N_ALEventListItem *thisNode, *nextNode;
    s16 evtType;

    thisNode = (N_ALEventListItem *)seqp->evtq.allocList.next;
    while (thisNode) {
        nextNode = (N_ALEventListItem *)thisNode->node.next;
        evtType = thisNode->evt.type;
        if (evtType == 0x17 || evtType == 0x18) {
            if (thisNode->evt.msg.osc.vs == vs) {
                (*seqp->stopOsc)(thisNode->evt.msg.osc.oscState);
                {
                    ALLink *ln = (ALLink *)thisNode;
                    if (ln->next) {
                        ln->next->prev = ln->prev;
                    }
                    if (ln->prev) {
                        ln->prev->next = ln->next;
                    }
                }
                if (nextNode)
                    nextNode->delta += thisNode->delta;
                {
                    ALLink *element = (ALLink *)thisNode;
                    ALLink *after = &seqp->evtq.freeList;
                    element->next = after->next;
                    element->prev = after;
                    if (after->next) {
                        after->next->prev = element;
                    }
                    after->next = element;
                }
                if (evtType == 0x17)
                    vs->flags = vs->flags & 0xFE;
                else
                    vs->flags = vs->flags & 0xFD;
                if (!vs->flags)
                    return;
            }
        }
        thisNode = nextNode;
    }
}
