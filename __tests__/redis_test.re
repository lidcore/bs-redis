open BsCallback;

open Tape;

test("get/set", t => {
  t.plan(1);
  let client = Redis.init();
  BsCallback.finish(
    Redis.set(client, "ping", "pong")
    >> (
      (_) =>
        Redis.get(client, "ping")
        >> (
          res =>
            Redis.quit(client)
            >> (
              (_) => {
                t.equalStr(res, "pong");
                BsCallback.return();
              }
            )
        )
    ),
  );
});
