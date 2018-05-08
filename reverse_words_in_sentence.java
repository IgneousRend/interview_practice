import java.util.*;

public class main {

    public static void reverse(char[] s, int i, int j)
    {
        while(i<j)
        {
            s[i] = (char) (s[i] ^ s[j]);
            s[j] = (char) (s[i] ^ s[j]);
            s[i] = (char) (s[i] ^ s[j]);
            i++;
            j--;
        }
    }

    public static void reverseWord(char[] s)
    {
        int n = s.length;
        int start = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i]==' ')
            {
                reverse(s, start, i-1);
                start = i+1;
            }
        }

        reverse(s, start, n-1);
        reverse(s, 0, n-1);

    }


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.next();
        char[] t = s.toCharArray();
        reverseWord(t);
        System.out.print(t);
    }
}
