/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function (path) {
    let st = []
    st.push('/')

    for (let i = 0; i < path.length; i++) {
        let c = path[i];

        if (c == '/') {
            if (st.length > 0 && st[st.length - 1] == c) {
                continue;
            }
        }
        st.push(c);
    }

    if (st[st.length - 1] == '/') {
        st.pop();
    }

    let Ans = "";
    while (st.length > 0) {
        Ans += st.pop();
    }

    Ans = Ans.split("").reverse().join("");

    let Part = Ans.split("/");

    let Res = []

    for(let p of Part){
        // console.log(p)
        if(p == ""){
            continue;
        }
        if(p == "."){
            continue;
        }
        else if(p == ".."){
            Res.pop();
            continue;
        }
        Res.push(p)
    }

    return "/" + Res.join("/")
};