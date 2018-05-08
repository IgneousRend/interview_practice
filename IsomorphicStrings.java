import java.util.HashMap;

public class IsomorphicStrings {

    private static boolean isomorphic(String a, String b)
    {
        if(a == null || b == null || a.length() != b.length())
            return false;

        HashMap<Character, Character> map = new HashMap<>();

        for(int i=0; i<a.length(); i++)
        {
            char s = a.charAt(i);
            char t = b.charAt(i);

            if(map.containsKey(s))
            {
                if(map.get(s) != t)         return false;
            }
            else
            {
                if(map.containsValue(t))    return false;
                else
                    map.put(s, t);
            }
        }

        return true;
    }


    public static void main(String[] args) {
        String a = "foo";
        String b = "egg";
        System.out.println(isomorphic(a, b));
    }
}
