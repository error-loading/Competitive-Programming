import java.util.*;
import java.io.*;
public class Knapsack3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
 
    public static void main(String[] args) throws IOException{
        int n = readInt(), m = readInt(), maxW = 5000;
        long dp[] = new long [maxW + 1];
        for (int i = 1; i<=n; i++) {
            long amt = readLong(), w = readLong(), val = readLong();
            for (int k = 1; k<= amt; k*=2) {
                long cost = k * w, value = k*val; amt -=k;
                for(int j = maxW; j>=cost; j--) {
                    dp[j] = Math.max(dp[j], dp[(int)(j - cost)] + value);
                }
            }
            if (amt > 0) {
                long cost = amt * w, value = amt * val;
                for (int j = maxW; j>=cost; j--) {
                    dp[j] = Math.max(dp[j], dp[(int)(j - cost)] + value);
                }
            }
        }

        long ans = Long.MIN_VALUE;
        for(int i = 1; i<= m; i++) {
            int cap = readInt(); long cost = readLong();
            ans = Math.max(ans, dp[cap] - cost);
        }
        System.out.println(ans);
    }
  
 
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }  
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}