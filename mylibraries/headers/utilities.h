/*
 * Utility.h
 *
 *  Created on: 29 set 2015
 *      Author: piero
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::find_if

#define ND 		numeric_limits<int>::max()
#define MINF 	numeric_limits<int>::min()
#define DMAX 	numeric_limits<double>::max()
#define DMINF 	numeric_limits<double>::min()

using namespace std;


// Mi definisco un predicato che uso nella map per cambiare il modo in cui ordina di default
// Infatti in ordine lessicografico 1 viene dopo 01, mentre a me interessa che si tenga conto
//  anche della lunghezza e quindi 1 venga prima di 01
/*struct strsize_less
{
    bool operator()(string const& l, string const& r) const
    {
        if (l.size() < r.size())
            return true;

        if (l.size() > r.size())
            return false;

        return l < r;
    };
};*/


template <typename T>
vector<T> append_vectors(const vector<T> *a,const vector<T> *b){
        vector<T> res = *a;

        res.insert(res.end(), b->begin(), b->end());

        return res;

}

template <typename T, typename Iterator>
vector<T> prefix_vector(vector<T>* a, Iterator pref_end){
	vector<T> res(a->begin(), pref_end);

	return res;
}


template <typename T>
ostream& operator<<(ostream& os, const vector<T> obj)
{
	os<<"[ ";
	for(auto i=obj.begin(); i!=obj.end(); ++i)
		os<< *i <<" ";
	os<<"]";

	return os;
}


string intTostring (int a);

int stringToint(string str);

string charToString(char c);

string trimRight(string str);




/**
 * Given an alpha values for a Normal Gaussian Distribution N(0,1), return the value of U_alpha, that is Z-alpha for N(0,1).
 * It define the bound value for accepting or rejecting an hypothesis, adopting the N(0,1).
 * @param alpha
 * @return  U-alpha value: the z-value for N(0,1), the bound value for accepting and rejecting area.
 */
double u_alpha_score(double alpha);


/**
 * Compute the Z-alpha value for a two proportions test, for two populations, and two samples having the same size. It's a one tailed test.
 * Z-alpha bound value for accepting and rejecting hypothesis, given an alpha value.
 * An upper value of alpha correspond to a bigger area of rejecting state: the process will reject more merge, reducing the Type II error and increasing the Type I error.
 * Type I error means here is: probability to reject a useful merge respect to the error introduced. It's alpha.
 * Type II error means here is: probability to accept a dangerous merge, respecto to the error introduced.
 * If you want an accurate final dfa you would increase the value of alpha. If you want a smaller dfa you wold decrease the value of alpha.
 * @param prop1
 * @param prop2
 * @param sample_size
 * @param alpha
 * @param &dev_std_h0
 * @return Z-alpha value for two proportions test with 2 populations
 */
double z_alpha_from_u_alpha_two_proportions_test(double prop1, double prop2, int sample_size, double alpha, double* dev_std_h0);


/**
 * Doesn't have the dev. std. as parameter. See the other "z_alpha_from_u_alpha_two_proportions_test" function.
 * @param prop1
 * @param prop2
 * @param sample_size
 * @param alpha
 * @return Z-alpha value for two proportions test with 2 populations
 */
double z_alpha_from_u_alpha_two_proportions_test(double prop1, double prop2, int sample_size, double alpha);


bool approximation_conditions_binomial_to_gaussian_distr(double p_est, double q_est, int sample_size);


string intTostring(int a);

int stringToint(string str);

string charToString(char c);

int getPoisson(double lambda);


double ncd(double comp_x, double comp_y, double comp_xy);


// trim from start
inline string &ltrim(string &s) {
        s.erase(s.begin(), find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace))));
        return s;
}

// trim from end
inline string &rtrim(string &s) {
        s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
}

// trim from both ends
inline string &trim(string &s) {
        return ltrim(rtrim(s));
}


#endif /* UTILITIES_H_ */
