// Entry point
[@bs.val] external document: Js.t({..}) = "document";

let rootElement = document##getElementById("root");
ReactDOMRe.render(<App />, rootElement);
