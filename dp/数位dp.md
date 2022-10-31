数位dp

1.求0到n之间的数字中有多少个数字他们每一位都不相同

```
class Solution {
    public static int f(String s, int i, int mask, boolean isLimited, boolean isNum){
        if(i == s.length())
            return isNum ? 1 : 0;
        int res = 0;
        if (!isNum) //选择跳过数字
            res = f(s,i+1,mask,false, false);
        int up = isLimited ? (int)(s.charAt(i)-'0'):9;
        int down = isNum ? 0:1;   //上界和下界地判断很有必要
        for (int j = down; j <= up; j++) {
            if((mask >> j&1)==0){
                res += f(s, i+1, mask|(1<<j),isLimited && (j==up),true);
            }
        }
        return res;
    }
    public static int countSpecialNumbers(int n){
        String s = Integer.toString(n);
//        System.out.println(s);
        return f(s,0,0,true, false);
    }

    public static void main(String[] args) {
        int n = 0;
        int sum = countSpecialNumbers(n);
        System.out.println(sum);
    }
}
```

```

```
