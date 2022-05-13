<p align="center">
  <img width="100" height="100" src="https://github.com/PacketSender642/taxi-lang/blob/main/resources/oncoming-taxi_1f696.png?raw=true">
</p>

[![ci](https://github.com/PacketSender642/taxi-lang/workflows/ci/badge.svg)](https://github.com/PacketSender642/taxi-lang/workflows/ci/badge.svg)
![Discord](https://img.shields.io/discord/974562247877734440?color=%237289da&label=Discord%20server)

# Taxi

An event driven compiled language written in C

## Building

its simple:
```bash
$ git clone --recurse https://github.com/PacketSender642/taxi-lang.git
$ cd taxi/taxic; make
```

## Samples

```taxi
on run { # kinda like the main function!
  puts("Hello taxi!");
}
```
More in `samples/`

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update samples as appropriate.

## License for `taxic/`
[MIT](https://choosealicense.com/licenses/mit/)

## License for `stdlib/`
[The Unlicense](https://choosealicense.com/licenses/unlicense/)
