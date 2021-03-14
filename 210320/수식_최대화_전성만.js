const solution = (expression) => {
    let arr_math = [], arr_sym = [];
    let num = 0;
    for (let i = 0; i < expression.length; i++) {
        if (Number.isInteger(expression[i]-'0')) {
            num *= 10;
            num += (expression[i] - '0');
        } else {
            arr_math.push(num);
            num = 0;
            arr_sym.push(expression[i]);
        }
    }
    arr_math.push(num);    
    let sym = ["*-+", "*+-", "+*-", "+-*", "-*+", "-+*"];
    let answer = 0;
    for (let i = 0; i < 6; i++) {
        let tmp_math = arr_math, tmp_sym = arr_sym;
        for (let j = 0; j < 3; j++) {
            if (tmp_math.length == 1) break;
            let tmp_math2 = [], tmp_sym2 = [];
            tmp_math2.push(tmp_math[0]);
            for (let k = 1; k < tmp_math.length; k++) {
                if (tmp_sym[k-1]==sym[i][j]) {
                    let tmp_num = tmp_math2.pop();
                    tmp_math2.push(eval(tmp_num+sym[i][j]+tmp_math[k]));
                } else {
                    tmp_math2.push(tmp_math[k]);
                    tmp_sym2.push(tmp_sym[k-1]);
                }
            }
            tmp_math = tmp_math2;
            tmp_sym = tmp_sym2;
        }
        if (answer < Math.abs(tmp_math[0])) answer = Math.abs(tmp_math[0]);
    }
    return answer;
}