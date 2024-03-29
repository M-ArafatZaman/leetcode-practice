import java.util.HashMap;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> ct = new HashMap<String, List<String>>();
        List<List<String>> result = new ArrayList<List<String>>();
        char[] tmp;
        String key;
        for (String i : strs) {
            tmp = i.toCharArray();
            Arrays.sort(tmp);
            key = new String(tmp);
            tmp = null;
            if (ct.get(key) == null) {
                ct.put(key, new ArrayList<String>());
            }
            ct.get(key).add(i);
        };

        for (String k : ct.keySet()) {
            result.add(ct.get(k));
        }

        ct = null;

        return result;
    }
}