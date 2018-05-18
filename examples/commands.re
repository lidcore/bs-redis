open BsCallback;

let c = Redis.init();

BsCallback.finish(
  Redis.set(c, "bingo2", "bingo")
  >> ((_) => Redis.quit(c) >> ((_) => BsCallback.return())),
);
