[%bs.raw {|require("tailwindcss/dist/tailwind.min.css")|}];
// Entry point
[@bs.val] external document: Js.t({..}) = "document";

let rootElement = document##getElementById("root");
ReactDOMRe.render(<Final />, rootElement);
