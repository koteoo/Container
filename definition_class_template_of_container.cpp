//Определение класса template_class_of_container
using namespace std;




//Constructor
template <class T> Container_t<T>::Container_t(int length):m_length(length) {
	if (length <=0) {
		ex();
	}
	m_data = new T[length];
	put_into_container();
}
//Constructor of copying
template <class T> Container_t<T>::Container_t(Container_t  &obj) {
	m_length = obj.m_length;
	m_data = new T[m_length];
	for (int i = 0;i<m_length; i++) {
		m_data[i] = obj.m_data[i];
	}
}

//Assignment operator
template <class T> Container_t<T> &Container_t<T>::operator=(Container_t &obj) {

	if (this != &obj) {
		m_length = obj.m_length;
		delete[] m_data;
		m_data = new T[m_length];
		for (int i = 0; i < m_length;i++) {
			m_data[i] = obj.m_data[i];
		}
		return *this;
	}

}

//Destructor
template <class T> Container_t<T>:: ~Container_t() {
	delete[]m_data;
}
//Putting into all container
template <class T> void Container_t<T>::put_into_container() {
	for (int i = 0; i < m_length;i++) {
		
		cin >> m_data[i];

	}
}
//Erasing all of container
template <class T> void Container_t<T>::erase() {
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}
//Get length of container
template <class T>int Container_t<T>::get_length()const {
	return m_length;
}
//Get element of container
template <class T> T Container_t<T>::get_element(int val)const {
	if (val>=0 && val < m_length) {
		return m_data[val];
	}
	else {
		return 0;
	}


}
//Get all elements of container
template <class T> void Container_t<T>::get_elements(){
	for (int i = 0; i < m_length; i++) {
		cout << m_data[i] << " ";
	}
}
//Changing of size without of destroing
template <class T>void Container_t<T>::resize(int new_length) {

	if (new_length == m_length) {
		return;
	}

	if (new_length <= 0) {

		erase();
		return;
	}

	int *data = new int[new_length];

	if (m_length > 0) {
		int elements_to_copy = (new_length > m_length) ? m_length : new_length;

		for (int i = 0; i < elements_to_copy; i++) {
			data[i] = m_data[i];
		}
	}

	delete[] m_data;


	m_data = data;
	m_length = new_length;

}
//Changing of size with destroing
template <class T>void Container_t<T>::resize_destroy(int new_length) {//Resizing without copying
	if (new_length == m_length) {
		return;
	}
	if (new_length <= 0) {
		return;
	}
	erase();
	m_data = new int[new_length];
	m_length = new_length;

}
//Inserting into specifical place
template <class T>void Container_t<T>::insert_to(int index, int value) {

	int *data = new int[m_length + 1];


	for (int before = 0; before < index; before++) {
		data[before] = m_data[before];
	}

	data[index] = value;

	for (int after = index; after < m_length; after++) {
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_length;

}
template <class T>void Container_t<T>::insert_to_beginning(int value) {
	insert_to(0, value);
}
template<class T>void Container_t<T>::insert_to_end(int value) {
	insert_to(m_length, value);
}
//Removing specifical of value
template <class T>void Container_t<T>::remove(int index) {



	int *data = new int[m_length - 1];

	if (m_length == 1) {
		erase();
		return;
	}

	for (int before = 0; before < index; before++) {
		data[before] = m_data[before];
	}
	for (int after = index + 1; after < m_length; after++) {
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_length;

}
template <class T>void Container_t<T>::remove_beginning() {
	remove(0);
}
template <class T>void Container_t<T>::remove_end() {

	remove(m_length - 1);
}

//Explicit typing for int

Container_t<int>::Container_t(int length):_length(length) {
	if (length <= 0) {
		ex();
	}

	_data = new int[length];
	cout << "The Length of the array: " << _length << endl;
	cout << "Put data into the array: \n";
	put_into();
}


void Container_t<int>::put_into() {
	for (int i = 0; i < _length; i++) {
		if (!(cin >> _data[i])) {
			erase();
			cin.clear();//Cleaning of this stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//Checking this thread for a number
			throw "ERROR: the incorrect input\0";
		}
	}


}

void Container_t<int>::erase() {
	delete[] _data;
	_data = nullptr;
	_length = 0;
}

char *ex() { throw "ERROR: out of array or incorrect data!"; }