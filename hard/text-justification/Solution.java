//https://leetcode.com/problems/text-justification/
public class Solution {

    private String[] words;
    private int[] spaces;
    private int maxWidth;

    private String fullyJustifyLine(int currLen, int l, int r) {
        StringBuilder justified = new StringBuilder();
        int extraSpaces = maxWidth - currLen;

        //If there is only one word.
        if (l == r) {
            //Add word
            justified.append(words[l]);

            //Add extra spacing
            for (int i = 0; i < extraSpaces; i++)
                justified.append(' ');

            return justified.toString();
        }
        
        //Distribute spaces
        for (int i = r; i > l; i--) {
            spaces[i] = extraSpaces / (i-l);
            extraSpaces -= spaces[i]++;
        }

        //Construct line
        for (int i = l; i <= r; i++) {
            //Add extra spacing
            for (int j = 0; j < spaces[i]; j++) justified.append(' ');

            //Add word
            justified.append(words[i]);
        }

        return justified.toString();

    }

    private String leftJustifyLine(int currLen, int l, int r) {
        StringBuilder justified = new StringBuilder(words[l]);

        //Add words
        for (int i = l+1; i <= r; i++)
            justified.append(' ').append(words[i]);

        //Add extra spacing
        for (int i = 0; i < (maxWidth-currLen); i++)
            justified.append(' ');

        return justified.toString();
    }

    public List<String> fullJustify(String[] words, int maxWidth) {
        //Set parameters
        this.words = words;
        this.maxWidth = maxWidth;
        this.spaces = new int[words.length];

        List<String> ans = new ArrayList<>();
        int l = 0, currLen = -1;

        for (int r = 0; r < words.length; r++) {
            int add = words[r].length() + 1;

            //Justify line with curr word
            if (currLen + add == maxWidth) {
                //Apply operation on curr line
                ans.add(fullyJustifyLine(currLen+add, l, r));

                //Move to next line
                currLen = -1;
                l = r+1;
            }

            //Justify line without curr word {
            else if (currLen + add > maxWidth) {
                //Apply operation on curr line
                ans.add(fullyJustifyLine(currLen, l, r-1));

                //Move to next line
                currLen = -1 + add;
                l = r;
            }

            //Add word to line
            else {
                currLen += add;
            }
        }

       //Left-justify last line
        if (l < words.length)
            ans.add(leftJustifyLine(currLen, l, words.length-1));

        return ans;
    }
}