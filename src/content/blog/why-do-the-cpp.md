---
title: 'Why do the C++ Standard Library does not have a function to lower/upper case a std::string?'
description: 'Lorem ipsum dolor sit amet'
pubDate: '26 October, 2025'
---

As we know, C++ is one of the older programming languages, officially renamed
from C with Classes to C++ and released in 1983.

Over the years, the language has matured considerably. But even so, it still
doesn't have simple `std::string::tolower()` or `std::string::toupper()` methods
for string manipulation.

I mean, even C's `<string.h>` has `char *strlwr(char *str)` and
`char *strupr(char *str)` functions. Now, I know what you're going to say:

> Why don't you just take a `std::string`, use the `.c_str()` method, and pass
> it to `strlwr` or `strupr`?

But let me tell you: the value returned by `.c_str()` is a `const char*`, which
means you can't modify the string through that pointer. Sure, you can use
`strcpy` to copy the value into another variable, but that only introduces extra
overhead.

So, what other options do we have?

1. We can iterate through the string and use a function called
   `tolower(char c)`.
2. We can use `std::transform` from the `<algorithm>` library to change the case
   of the string in one go.

Both methods are great, but the first, iterative method is somewhat verbose and
less commonly used nowadays.

## Using `std::transform`

The second method looks like this:

```cpp
#include <algorithm>
#include <cctype>
#include <string>

int main() {
    std::string sampleLower("this is a lower string");

    std::transform(
        sampleLower.begin(),
        sampleLower.end(),
        sampleLower.begin(),
        [](unsigned char c) {
            return std::toupper(c);
        }
    );

    return 0;
}
```

**Output:**

```sh
$ THIS IS A LOWER STRING
```

The `std::transform` function takes four parameters:

1. **Start:** The starting iterator from which you want to begin the
   transformation.
2. **End:** The ending iterator that specifies where the transformation should
   stop.
3. **Output start:** The iterator where the transformed output will be written.
   In our case, it's the same string we're transforming.
4. **Unary operator:** A function or callable object that will be applied during
   the transformation, such as `toupper` or `tolower`.

## What About Unicode Characters?

One important thing to note is that the basic `std::toupper` and `std::tolower`
functions operate on individual characters and do not provide full Unicode case
conversion. They are generally suitable for ASCII characters and depend on the
active C locale for other supported single-byte characters.

For Unicode text, using `std::wstring` alone is not enough to guarantee correct
case conversion. You may need a Unicode-aware library, such as ICU, to handle
characters and language-specific casing correctly.

## Conclusion

Compared with languages like Python, which provide simple `str.lower()` and
`str.upper()` methods, C++ requires a little more effort to perform string case
conversion.

Nevertheless, C++ remains a popular choice for writing fast, high-performance
system software.

---

**Full example:** 
```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{
    std::string sampleLower("this is a lower string");
    std::string sampleUpper("THIS IS A UPPER STRING");

    std::cout << sampleLower << std::endl;
    std::cout << sampleUpper << std::endl;
    std::cout << "----------------------" << std::endl;
    std::string sampleLower("this is a lower string");
    std::transform(sampleLower.begin(), sampleLower.end(), sampleLower.begin(), toupper); // Now this `sampleLower` is made upper
    std::transform(sampleUpper.begin(), sampleUpper.end(), sampleUpper.begin(), tolower); // Now this `sampleUpper` is made lower
    std::cout << sampleLower << std::endl;
    std::cout << sampleUpper << std::endl;
    return 0;
}
```

## References / Citations

1. [Stack Overflow — Convert a string to uppercase or lowercase](https://stackoverflow.com/a/313990/31691327)
2. [C/C++: Convert string to upper/lower case](https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/)
3. [cppreference —](https://en.cppreference.com/w/cpp/algorithm/transform.html)
   [`std::transform`](https://en.cppreference.com/w/cpp/algorithm/transform.html)
