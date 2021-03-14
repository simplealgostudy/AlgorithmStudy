const solution = (n, s, a, b, fares) => {
    let arr = Array(n+1).fill().map(()=>Array(n+1).fill(1e9));
    [...Array(n+1).keys()].map(i=>(arr[i][i++]=0));
    [...Array(fares.length).keys()].map(i=>(arr[fares[i][0]][fares[i][1]] = fares[i][2],arr[fares[i][1]][fares[i][0]] = fares[i++][2]));
    for (let k = 1; k < n+1; k++) {
        for (let i = 1; i < n+1; i++) {
            for (let j = 1; j < n+1; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
    var answer = 1e9;
    [...Array(n+1).keys()].map(i=>(answer = Math.min(answer, (arr[s][i] + arr[i][a] + arr[i++][b]))));
    return answer;
}