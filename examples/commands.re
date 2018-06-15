open BsAsyncMonad;
open BsAsyncMonad.Callback;

let c = Redis.init();

Callback.finish(
  Redis.set(c, "bingo2", "bingo")
  >> (_ => Redis.quit(c) >> (_ => Callback.return())),
);
