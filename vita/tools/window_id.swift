// Prints the ids of the windows of a process whose title contains a string (for
// screencapture -l). Used by tools/bench_vita3k.sh (SHOT) to capture the game window.
// usage: window_id <pid> [title substring]
import CoreGraphics
import Foundation

let pid = CommandLine.arguments.count > 1 ? Int(CommandLine.arguments[1]) ?? -1 : -1
let title = CommandLine.arguments.count > 2 ? CommandLine.arguments[2] : ""
let list = CGWindowListCopyWindowInfo([.optionAll], kCGNullWindowID) as? [[String: Any]] ?? []
for w in list {
    let owner = w[kCGWindowOwnerPID as String] as? Int ?? 0
    let layer = w[kCGWindowLayer as String] as? Int ?? -1
    let bounds = w[kCGWindowBounds as String] as? [String: Any] ?? [:]
    let height = bounds["Height"] as? Double ?? 0
    let name = w[kCGWindowName as String] as? String ?? ""
    if owner == pid && layer == 0 && height > 100 && (title.isEmpty || name.contains(title)) {
        print(w[kCGWindowNumber as String] as? Int ?? 0)
    }
}
