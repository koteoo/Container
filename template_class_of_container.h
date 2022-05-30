#pragma once

template <class T> class Container_t {

public:
	//Container_t() = default;
	Container_t(int length);
	Container_t(Container_t  &obj);
	Container_t &operator=(Container_t &obj);
	~Container_t();

	void put_into_container();
	void erase();
	int get_length()const;
	T get_element(int val)const;
	void get_elements();
	void resize(int new_length);
	void resize_destroy(int new_length);

	void insert_to(int index, int value);

	void insert_to_beginning(int value);
	void insert_to_end(int value);
	void remove(int index);
	void remove_beginning();
	
	void remove_end();
private:
	T *m_data=nullptr;
	int m_length;

};

//Explicit typing with parent's legacy
 template <> class Container_t<int>{
public:
	Container_t(int length);
	
	int get_length()const {
		return _length;
	}
	void put_into();
		
	void erase();
	
	
private:
	int *_data;
	int _length;


};

 char *ex();