class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> res;
      double kel=0;
      double fah =0;
      kel = celsius+273.15;
      fah = celsius*1.80+32.00;
      res.push_back(kel);
      res.push_back(fah);
      return res;  
    }
};