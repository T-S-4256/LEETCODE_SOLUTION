function fn(a,b,c){
    return a+b+c;
}


var once = function (fn) {
    flag = 0
    return function (...args) {
        if (flag) {
            return undefined
        }
        flag++
        return fn(...args);
    }
};


const onceFn = once(fn);

console.log(onceFn(1, 2, 3)); 
console.log(onceFn(4, 5, 6)); 
console.log(onceFn(7, 8, 9)); 


// Input: fn = (a,b,c) => (a + b + c), calls = [[1,2,3],[2,3,6]]
// Output: [{"calls":1,"value":6}]

// Input: fn = (a,b,c) => (a * b * c), calls = [[5,7,4],[2,3,6],[4,6,8]]
// Output: [{"calls":1,"value":140}]
