# demo for std::any breakage across library boundaries on macOS

To reproduce:

```
mkdir build && cd build
cmake .. && cmake --build .
ctest -V .
```

Expected example output when run on Linux or Windows:
```
1: genAny:      name=St10shared_ptrIiE  hash_code=488376882528701771
1: main:        name=St10shared_ptrIiE  hash_code=488376882528701771
1: typeid matches:      1
1: wrapped ptr: 0x55f3ad3c5ec0
1: wrapped value:       42
1/1 Test #1: pass_any_across_lib ..............   Passed    0.00 sec
```

Expected example output when run on macOS:
```
TODO
```
