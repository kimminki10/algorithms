echo "g++ -o a.out $1/$2/$2.cc"
g++ -o a.out $1/$2/$2.cc
echo "./a.out < input.txt"
./a.out < input.txt
echo "rm a.out"
rm a.out
