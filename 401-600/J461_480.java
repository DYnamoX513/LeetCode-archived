public class J461_480 {
    public static void main(String[] args) {
        J461_480 s = new J461_480();
//        s.smallestGoodBase_483("16035713712910626");
    }

    public String smallestGoodBase_483(String n) {
        long num = Long.parseLong(n);
        for (int exp = 60; exp >= 2; exp--) {
            long k = (long) Math.pow(num, 1.0 / exp);
            if (k == 1) continue;
            long mul = 1, sum = 1;
            for (int i = 0; i < exp; i++) {
                mul *= k;
                sum += mul;
            }
            if (sum == num)
                return String.valueOf(k);
        }
        return String.valueOf(num - 1);
    }

}
