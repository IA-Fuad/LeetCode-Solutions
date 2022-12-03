public class Solution {
    public string FrequencySort(string s) {
        Dictionary<char, int> frequency = new Dictionary<char, int>();
        
        for (int i = 0; i < s.Length; i++) {
            if (frequency.ContainsKey(s[i])) {
                frequency[s[i]]++;
            }
            else {
                frequency.Add(s[i], 1);
            }
        }
        
        var sortedS = new StringBuilder(s.Length);
        
        foreach (var (letter, count) in frequency.OrderByDescending(x => x.Value)) {
            for (int i = 0; i < count; i++) {
                sortedS.Append(letter);
            }
        }
        
        return sortedS.ToString();
    }
}