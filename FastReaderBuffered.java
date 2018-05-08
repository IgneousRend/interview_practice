import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FastReaderBuffered {

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        private FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next()
        {
            while(st == null || !st.hasMoreElements()) {
                try { st = new StringTokenizer(br.readLine()); }
                catch (IOException e) { e.printStackTrace(); }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }

        String nextLine()
        {
            String S = "";
            try { S = br.readLine(); }
            catch (IOException e) {e.printStackTrace();}
            return S;
        }

    }

    public static void main(String[] args) {
        FastReader input = new FastReader();
        int i = input.nextInt();
        System.out.println(i);
    }

}
