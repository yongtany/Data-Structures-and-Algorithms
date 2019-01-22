/* Stack! */

// functions: push, pop., peek, length

var letters = [];   // this is our stack

var word = 'racecar';

var rword = '';

// put letters of word into stack
for(var i = 0; i< word.length; i++) {
    letters.push(word[i]);
}

// pop off the stack in reverse order
for(var i =0; i< word.length; i++) {
    rword += letters.pop();
}

if(rword === word) {
    console.log(word + ' is a pallindrome.');
} else {
    console.log(word + ' is not a palindrome.');
}

// Crates a stack

var Stack = function () {
    this.count = 0;
    this.storage = {};

    // Adds a value onto the end of the stack
    this.push = function(value) {
        this.storage[this.count] = value;
        this.count++;
    }

    // Removes and returns the value at the end of the stack
    this.pop = function() {
        if(this.count === 0) {
            return undefined;
        }

        this.count--;
        var result = this.storage[this.count];
        delete this.storage[this.count];
        // delete 연산자는 오브젝트로 부터 해당 프로퍼티를 삭제합니다.
        return result;
    }

    this.size = function() {
        return this.count;
    }

    // Returns the value at the end of the stack
    this.peek = function() {
        return this.storage[this.count-1];
    }
}

var yongStack = new Stack();

yongStack.push(1);
yongStack.push(2);
console.log(yongStack.peek());
console.log(yongStack.pop());
console.log(yongStack.peek());
yongStack.push("yongtany");
console.log(yongStack.size());
console.log(yongStack.peek());
console.log(yongStack.pop());
console.log(yongStack.peek());