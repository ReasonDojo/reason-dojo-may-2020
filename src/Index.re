// This wasn't working...didn't know why, so I added it via a cdn to the index.html
// [%bs.raw {|require("tailwindcss/dist/tailwind.min.css")|}];
// Entry point
[@bs.val] external document: Js.t({..}) = "document";

let rootElement = document##getElementById("root");
ReactDOMRe.render(<Final />, rootElement);
