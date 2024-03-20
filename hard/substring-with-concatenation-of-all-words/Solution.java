class Solution {

    private Map<String, Integer> wordCount;

    private Integer wordLen, permLen;
    private String s;

    private boolean isValidPermutation(int l, int r) {
        //Initialize structure
        Map<String, Integer> currWordCount = new HashMap<>();

        //Move until dead end
        while (l < r) {
            //Fetch required data
            String subStr = this.s.substring(l, l + this.wordLen);
            int currCount = currWordCount.getOrDefault(subStr, 0) + 1;
            int maxCount = this.wordCount.getOrDefault(subStr, 0);

            //Return failure because of exceeded limit
            if (currCount > maxCount) return false;

            //Update current word count
            currWordCount.put(subStr, currCount);

            //Move left pointer
            l += this.wordLen;
        }

        return true;
    }

    public List<Integer> findSubstring(String s, String[] words) {
        //Initialize structures
        List<Integer> ans = new ArrayList<>();
        this.wordCount = new HashMap<>();

        //Initialize variables
        this.wordLen = words[0].length();
        this.permLen = this.wordLen * words.length;
        this.s = s;

        //Fill word count
        for (String word: words)
            this.wordCount.put(word, this.wordCount.getOrDefault(word, 0) + 1);

        //Loop through every permutation
        for (int i = 0; (i + this.permLen) <= s.length(); i++) {
            //Save index
            if (isValidPermutation(i, i + this.permLen))
                ans.add(i);
        }

        return ans;
    }
}
