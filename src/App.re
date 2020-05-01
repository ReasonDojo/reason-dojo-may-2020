/* Handy for debug, but you won't always get what you expect out. Most useful
   with records, string, ints, float, etc. */
[@bs.val]
external prettyStringify:
  ('a, [@bs.as {json|null|json}] _, [@bs.as {json|2|json}] _) => string =
  "JSON.stringify";

/* You can use it like:
        let person = {name: "Joe"}
      <pre>
        <code>
          {prettyStringify(person)} // Returns the result of JSON.stringify(person, null, 2)
        </code>
      </pre>
   */

/* An example of making a new type */
type person = {name: string};
let joe = {name: "Joe"};

/* Use this to make pretty tailwind styles. Autocomplete in your editor will
   help a lot for knowing what you can pass in, or just ask in the Discord, and
   @jsjoeio can you you! */
let tailwind = TW.make;

/*
   You can get the current time as milliseconds (actually a float, not an integer) with:
   let now = Js.Date.now()
 */

/* Quick note about arithmetic on float:
       Normally to add, subtract, multiple, divide we do e.g. 1 + 1, 1 - 1, 1 * 1, 1 / 1

       That works perfectly fine for `int`s (integers)! But you need to use +., -., *., and /. for floats:
       1.0 -. 2.0 = -1.0
       1.0 +. 2.0 = 3.0
       1.0 *. 2.0 = 2.0
       1.0 /. 2.0 = 0.5

     You can get an int from a float with: int_of_float(1.0) => 1
     And you can get a float from an int with: float_of_int(1) => 1.0

     So this will work if you need it:
     float_of_int(10) +. 2.0 = 12.0

     We know, it's a bit of a bummer to have to tell the difference between adding
     ints and adding floats, but it has its advantages too!
   */

let containerClass =
  tailwind([
    MaxWidth(MaxW6xl),
    Margin(MxAuto),
    Padding(Pt20),
    TextAlign(TextCenter),
  ]);

let headlineClass =
  tailwind([FontSize(Text6xl), FontWeight(FontLight), Margin(Mb4)]);

[@react.component]
let make = () => {
  React.(
    <div className=containerClass>
      <p className=headlineClass>
        {j|Stretch your arms, and let's get started|j}->string
      </p>
    </div>
  );
};
