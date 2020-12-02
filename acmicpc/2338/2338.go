package main

import(
    "fmt"
    "bufio"
    "os"
    "math/big"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func printf(s string, a...interface{}) { fmt.Fprintf(out, s, a...) }
func scanf(s string, a...interface{}) { fmt.Fscanf(in, s, a...) }

func main() {
    defer out.Flush()

    var a, b string
    scanf("%s\n%s\n", &a, &b)

    biga, _ := new(big.Int).SetString(a, 10)
    bigb, _ := new(big.Int).SetString(b, 10)

    bigc := new(big.Int)
    printf("%v\n", bigc.Add(biga, bigb))
    printf("%v\n", bigc.Sub(biga, bigb))
    printf("%v\n", bigc.Mul(biga, bigb))
}
