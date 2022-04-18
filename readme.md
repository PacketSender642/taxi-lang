<p align="center">
  <img width="69" height="69" src="https://github.com/PacketSender642/taxi-lang/blob/main/resources/oncoming-taxi_1f696.png?raw=true">
</p>

[![ci](https://github.com/PacketSender642/taxi-lang/workflows/ci/badge.svg)](https://github.com/PacketSender642/taxi-lang/workflows/ci/badge.svg)


# Taxi

a "english-like" compiled language written in C

## Building

Depends on the components you want, for the compiler its simple:
```bash
$ git clone https://github.com/orangeduck/mpc.git taxic/deps/mpc
$ cd taxic; make
```

## Samples

```taxi
say "Hello, world"
```
More in `samples/`

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License for `taxic/`
[MIT](https://choosealicense.com/licenses/mit/)

## License for `stdlib/`
[The Unlicense](https://choosealicense.com/licenses/unlicense/)
