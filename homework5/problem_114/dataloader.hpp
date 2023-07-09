#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include<sstream>


using namespace std;



// Change this file as you want or add more files






class Vocabulary
{
private:
	// Choose a proper container from STL.
	map<string, int> m;
	int num = 1;

public:
	vector<int> insertSentReturnIds(string sentence){
		vector<int> numlist;
		int len = sentence.length();
		int p = 0;
		for(int i = 0; i <= len; i++)
		{
			if(sentence[i] == ' ' or i == len)
			{
				string word_temp(sentence.begin()+p, sentence.begin()+i);
				if(m.count(word_temp))
				{
					numlist.push_back(m[word_temp]);
				}
				else
				{
					m.insert(make_pair(word_temp, num));
					numlist.push_back(num);
					num++;
				}
				p = i + 1;
			}
		}
		return numlist;

		//Enter your code here.
		//This function should build vocabulary and at the same time return a sentence encoding.
	}
};


class DataLoader{
private:
	//Enter your code here
public:
	vector<int> _rand_order;
	int batch_size=0;
	vector<vector<int>> origin;
	vector<vector<vector<int>>> _batch;
	void setBatchSize(int N){
		_batch.clear();
		this->batch_size = N; // can also change
		//to do
		int p = 0;
		int times = _rand_order.size() / batch_size;
		int mod = _rand_order.size() % batch_size;
		if(times == 0)
		{
			times = 1;
			mod = 0;
			batch_size = _rand_order.size();
		}
		for(int i = 0; i < times; i++)
		{
			int maxl = 0;
			for(int j = 0; j < batch_size; j++)
			{
				maxl = max(maxl, (int)origin[_rand_order[p+j]].size());
			}
			vector<vector<int>> temp;
			temp.clear();
			for(int j = 0; j < batch_size; j++)
			{
				
				temp.push_back(origin[_rand_order[p+j]]);
				
				// _batch[batch_p].insert(_batch[batch_p].end(),origin[_rand_order[p+j]]);
				int k = maxl - temp[j].size();
				while(k--)
					temp[j].push_back(0);
			}
			_batch.push_back(temp);
			// batch_p++;
			p += batch_size;
		}
		if(mod > 0)
		{
			int maxl = 0;
			for(int j = 0; j < mod; j++)
			{
				maxl = max(maxl, (int)origin[_rand_order[p+j]].size());
			}

			vector<vector<int>> temp;
			temp.clear();

			for(int j = 0; j < mod; j++)
			{
				
				temp.push_back(origin[_rand_order[p+j]]);
				
				// _batch[batch_p].insert(_batch[batch_p].end(),origin[_rand_order[p+j]]);
				int k = maxl - temp[j].size();
				while(k--)
					temp[j].push_back(0);
			}
			_batch.push_back(temp);

		}

	}

	void setOrder(vector<int>& x){
		_rand_order = x; // can also change
	}

	void addData(vector<int> sent_encoding){
		origin.push_back(sent_encoding);
		//Enter you code here;
	}

	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		// Add more using statement here
		// hint: using value_type = ?
		//       using reference = ?
		using value_type = vector<vector<int>>;
		using reference =  vector<vector<int>>&;
		using pointer =    vector<vector<int>>*;
		Iterator(pointer ptr): _ptr(ptr){}
		reference operator*() const{
			return *_ptr;
		}
		pointer operator->()
		{
			return _ptr;
		}
		Iterator& operator++(){
			_ptr++;
			return *this;
		}

		friend bool operator!=(const Iterator& a, const Iterator& b)
		{
			return a._ptr != b._ptr;
		}
		//Define your constructor and functions that are needed for a Iterator.
		private:
		pointer _ptr;
		// Add what where variable you want here to make the Iterator functional.
	};

	Iterator begin() {
		return Iterator(&_batch[0]);
		//Enter your code here.
	}
	Iterator end() {
		int size = _batch.size();
		return Iterator(&_batch[size]);
		//Enter your code here.
	}

};






