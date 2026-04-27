template<class K, class V>
class Map {
    private:
        struct Node {
            K key;
            V value;
        };

        struct Element {
            K key;
            V value;
            int index;
        };

        Node* data;
        int size;
        int capacity;

        void Resize() {
            capacity *= 2;
            Node* newData = new Node[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

    public:
        Map() : size(0), capacity(10) {
            data = new Node[capacity];
        }

        ~Map() {
            delete[] data;
        }

        void Set(const K& key, const V& value) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == key) {
                    data[i].value = value;
                    return;
                }
            }
            if (size == capacity) {
                Resize();
            }
            data[size++] = {key, value};
        }

        bool Get(const K& key, V& value) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == key) {
                    value = data[i].value;
                    return true;
                }
            }
            return false;
        }

        int Count() {
            return size;
        }

        void Clear() {
            size = 0;
            delete[] data;
            data = new Node[capacity];
        }

        bool Delete(const K& key) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == key) {
                    for (int j = i; j < size - 1; j++) {
                        data[j] = data[j + 1];
                    }
                    size--;
                    return true;
                }
            }
            return false;
        }

        bool Includes(const Map<K, V>& other) {
            for (int i = 0; i < other.size; i++) {
                bool found = false;
                for (int j = 0; j < size; j++) {
                    if (data[j].key == other.data[i].key && data[j].value == other.data[i].value) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
            return true;
        }

        V& operator[](const K& key) {
            for (int i = 0; i < size; i++) {
                if (data[i].key == key) {
                    return data[i].value;
                }
            }
            if (size == capacity) {
                Resize();
            }
            data[size++] = {key, V()};
            return data[size - 1].value;
        }

        class Iterator {
            private:
                Node* ptr;
                int index;
            public:
                Iterator(Node* p, int idx) : ptr(p), index(idx) {}

                bool operator!=(const Iterator& other) const { 
                    return ptr != other.ptr; 
                }
        
                Iterator& operator++() { 
                    ptr++; 
                    index++; 
                    return *this; 
                }
                
                Element operator*() const {
                    return {ptr->key, ptr->value, index};
                }
        };

        Iterator begin() const {
            return Iterator(data, 0);
        }

        Iterator end() const {
            return Iterator(data + size, size);
        }

};