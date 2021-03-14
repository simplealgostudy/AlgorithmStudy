const solution = (n, arr1, arr2) => {
    return [...Array(n).keys()].map(i => ((arr1[i]|arr2[i++]).toString(2).padStart(n, '0').split('').map((x)=>x!='1'?' ':'#').join('')));
}