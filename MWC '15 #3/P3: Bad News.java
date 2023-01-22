// https://dmoj.ca/problem/mwc15c3p3
// MWC '15 #3 P3: Bad News

import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, q; static char g[][];
    static boolean vis[][];
    public static void main(String[] args) throws IOException{
      n = readInt();  q = readInt(); g = new char[n][n];
      for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
          g[i][j] = readCharacter();
        }
      }
      for (; q> 0; q--) {
        String word = readLine(); boolean found = false;
        vis = new boolean[n][n];
        done:
        for (int i = 0; i< n; i++) {
          for (int j = 0; j< n; j++) {
            if (g[i][j] == word.charAt(0)) {
              found = dfs(i, j, 1, word);
              if (found) break done;
            }
          }
        }
        System.out.println(found? "good puzzle!": "bad puzzle!");
      }
    }
    static boolean dfs(int r, int c, int idx, String word) {
      if (idx == word.length()) return true;
      vis[r][c] = true;
      for (int dr = -1; dr<=1; dr++) {
        for (int dc = -1; dc <=1; dc++) {
          int nr = r+ dr, nc = c+ dc;
          if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc] || g[nr][nc] != word.charAt(idx)) continue;
          if (dfs(nr, nc, idx+1, word)) return true;
        }
      }
      vis[r][c] = false; return false;
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

