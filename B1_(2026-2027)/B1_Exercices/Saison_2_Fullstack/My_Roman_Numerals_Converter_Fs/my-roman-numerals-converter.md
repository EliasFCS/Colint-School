# My Roman Numerals Converter

**Submit directory:** `ex00`
**Submit file:** `my_roman_numerals_converter*`
**Languages:** It needs to be completed in the language you are working on right now. If you are doing Bootcamp JavaScript, then JavaScript (file extension `.js`). If you are doing Bootcamp Ruby, then Ruby (`.rb`). Same for Python, Java, C++, Rust, ...

## Description

Write a function to convert normal numbers to Roman Numerals.

The Romans wrote numbers using letters — I, V, X, L, C, D, M. (Notice these letters have lots of straight lines and are hence easy to carve into stone tablets.)

```
 1  => I
10  => X
 7  => VII
```

There is no need to be able to convert numbers larger than about 3000. (The Romans themselves didn't tend to go any higher.)

Wikipedia says: modern Roman numerals... are written by expressing each digit separately, starting with the leftmost digit and skipping any digit with a value of zero.

To see this in practice, consider the number `1990`.

In Roman numerals, `1990` is `MCMXC`:
```
1000 = M
 900 = CM
  90 = XC
```

`2008` is written as `MMVIII`:
```
2000 = MM
   8 = VIII
```

See also: [http://www.novaroma.org/via_romana/numbers.html](http://www.novaroma.org/via_romana/numbers.html)

It will return a string with the Roman numeral.

## Examples

| Example | Input | Return Value |
|---|---|---|
| 00 | 14 | `"XIV"` |
| 01 | 79 | `"LXXIX"` |
| 02 | 845 | `"DCCCXLV"` |
| 03 | 2022 | `"MMXXII"` |
