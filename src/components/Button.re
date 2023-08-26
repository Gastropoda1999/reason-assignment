module Styles = {
  open Css;

  let container =
    merge([
      style([
        borderWidth(zero),
        borderRadius(zero),
        color(hex("fafafa")),
        cursor(`pointer),
        display(inlineBlock),
        flexBasis(pct(25.)),
        fontSize(em(1.5)),
        lineHeight(`abs(2.)),
        outlineStyle(none),
        transitions([
          transition(
            ~duration=300,
            ~timingFunction=easeOut,
            "background-color",
          ),
          transition(~duration=300, ~timingFunction=easeOut, "color"),
        ]),
        hover([backgroundColor(hex("fafafa"))]),
      ]),
    ]);

  let variant = colorCode =>
    style([
      backgroundColor(hex(colorCode)),
      hover([color(hex(colorCode))]),
    ]);

  let blue = variant("6d71ff");
  let green = variant("3bf3a9");
  let orange = variant("ff8754");
  let lightGray = variant("aabbcc");
  let orangeYellow = variant("f0a500");
  let emeraldGreen = variant("2ecc71");
  let red = variant("e74c3c");
  let blue2 = variant("3498db");
  let pumpkinOrange = variant("d35400");
};

[@react.component]
let make = (~action: Store.action, ~text) => {
  let color =
    switch (action) {
    | Clear => Styles.lightGray
    | Percent => Styles.orangeYellow
    | PosNeg => Styles.green
    | Add => Styles.emeraldGreen
    | Divide => Styles.blue
    | Equals => Styles.blue2
    | Multiply => Styles.pumpkinOrange
    | Subtract => Styles.orange
    | _ => Styles.red
    };

  let addOperation = Store.useAddOperation();
  let onClick = React.useCallback(_ => addOperation(action));

  <button className={Css.merge([Styles.container, color])} onClick>
    text->React.string
  </button>;
};
