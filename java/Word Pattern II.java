
public class Solution {
    public boolean wordPatternMatch(String pattern, String str) {
        HashMap<Character, String> map =new HashMap<Character, String>();
        HashSet<String> set = new HashSet<String>();
        
        
        return helper(pattern,str,map,set,0,0);
        
    }
    public boolean helper(String pattern, String str, HashMap<Character, String> map,HashSet<String> set,int i,int j){
        int pL = pattern.length();
        
        if(pL == i && j==str.length()){
            return true;
        }
        if(pL == i|| j==str.length())return false;
        
        char pat = pattern.charAt(i);
        if(map.containsKey(pat) ){
            String scur = map.get(pat);
           if(!str.startsWith(scur,j)){
               return false;
           }  
           return helper(pattern,str,map,set,i+1,j+scur.length());
        }
      /*
      aab
      redredredd
      */
        for(int k = j;k<str.length();k++){
            String cur = str.substring(j,k+1);
            if(set.contains(cur)){
                continue;
            }
            
            map.put(pat,cur);
            set.add(cur);
            if(helper(pattern,str,map,set,i+1,k+1) ){
                return true;
            }
            
            map.remove(pat);
            set.remove(cur);
        }
        return false;
    }
}
