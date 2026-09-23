clean:
  rm -rf ./bin
  mkdir -p bin

build-example example:
  clang -Wall -o bin/{{example}} examples/{{example}}.c

build program:
  clang -Wall -o bin/{{program}} {{program}}/*.c

run program:
  ./bin/{{program}}
