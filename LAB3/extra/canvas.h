class Canvas {
    private:
        char** matrix;
        int columns;
        int lines;
    public:
        Canvas(int lines, int columns);
        void set_pixel(int x, int y, char value);
        void set_pixels(int count, ...);
        void clear();
        void print() const;
        ~Canvas();
};