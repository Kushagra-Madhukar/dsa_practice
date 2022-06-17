function* generateOdd(){
 yield 1;
 const generatorIn = generateOdd();
 while(true) {
   yield generatorIn.next().value + 2;
 }
}

const generator = generateOdd();
console.log(generator.next().value);
console.log(generator.next().value);
console.log(generator.next().value);
console.log(generator.next().value);
console.log(generator.next().value);
