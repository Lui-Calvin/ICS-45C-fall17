#ifndef MAPARRAY_H
#define MAPARRAY_H

#include<algorithm>
#include<iostream>
#include<iterator>
#include<string>

using namespace std;

template
<typename T1,typename T2>
class MapArray
{
	private:
		pair<T1,T2>* buf;
		int length = 0;
	public:
		struct iterator
		{
			typedef std::forward_iterator_tag iterator_category;
			typedef iterator self_type;
			typedef pair<T1,T2> value_type;
			typedef pair<T1,T2>& reference;
			typedef pair<T1,T2>* pointer;
			typedef ptrdiff_t difference_type;
			private:
				pointer buf;
			public:
				iterator(pointer ptr):buf(ptr){};
				self_type operator++(){++buf;return *this;}
				self_type operator++(int postfix){self_type cpy = *this; buf++;return cpy;}
				reference operator*(){return *buf;}
				pointer operator->(){return buf;}
				bool operator ==(const self_type& rhs){return buf == rhs.buf;}
				bool operator !=(const self_type& rhs){return buf != rhs.buf;}
		};
		MapArray()
		{
			buf = new pair<T1,T2>[10000];
		}

		int size()
		{
			return length;
		}
		int find(T1& key)
		{
			for(int i = 0;i < length;i++)
			{
				if(buf[i].first == key)
				{
					return i;
				}
			}
			return -1;
		}
		int& operator[](T1 key)
		{
			
			int index = find(key);
			if(index != -1)
			{
				return buf[index].second;
			} else {
				buf[length] = make_pair(key,T2(0));
				++length;
				sort(buf,buf+length);
				return buf[find(key)].second;
			}			
		}
		iterator begin()
		{
			return iterator(buf);
		}
		iterator end()
		{
			return iterator(buf+length);
		}
		~MapArray()
		{
			delete[] buf;
		}
};
#endif
