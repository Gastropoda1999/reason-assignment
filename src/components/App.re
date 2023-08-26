module Styles = {
  open Css;

  let buttons =
    style([
      display(`flex),
      selector(
        "&:last-of-type",
        [
        ],
      ),
    ]);

  let calculator =
    style([
      background(hex("EFEFEF")),
      borderRadius(px(0)),
      overflow(hidden),
      width(em(14.)),
    ]);

  let container =
    style([alignItems(`center), display(`flex), flexDirection(`column)]);

  let display =
    style([
      alignItems(center),
      color(hex("EFEFEF")),
      display(`flex),
      fontSize(em(1.5)),
      height(em(2.5)),
      justifyContent(flexEnd),
      padding2(~v=zero, ~h=em(1.)),
    ]);
};

[@react.component]
let make = () => {
  let display = Store.useDisplay();

  <div className=Styles.container>
    <Hero />
    <div className=Styles.calculator>
      <div className=Styles.buttons>
        <Button action=Subtract text="7" />
        <Button action=Add text="8" />
        <Button action=Equals text="9" />
      </div>
      <div className=Styles.buttons>
        <Button action=Percent text="4" />
        <Button action=Divide text="5" />
        <Button action=Multiply text="6" />
      </div>
      <div className=Styles.buttons>
        <Button action="1"->Input text="1" />
        <Button action=Clear text="2" />
        <Button action=PosNeg text="3" />
      </div>
    </div>
  </div>;
};
