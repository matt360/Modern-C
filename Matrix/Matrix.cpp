template<class T>
class Matrix {
public:
    Matrix(const std::vector<T>& A, const std::vector<T>& B) {
        for (int i = 0; i < A.size(); ++i)
            vec_of_vecs.push_back(B);
    }

    const Matrix operator+(const Matrix& other) const {
        Matrix result = *this;
        for (int i = 0; i < other.vec_of_vecs.size(); ++i)
            for (int j = 0; j < other.vec_of_vecs.at(0).size(); ++j)
                result.vec_of_vecs.at(i).at(j) += other.vec_of_vecs.at(i).at(j);

        return result;
    }

    void display() {
        for (auto& row : vec_of_vecs)
            for (auto& col : row)
                std::cout << col << " ";
    }

    std::vector<std::vector<T> > vec_of_vecs;
};

int main(int argc, const char * argv[]) {
    vector<int> A { 4, 35, 80, 123, 12345, 44, 8, 5 };
    solution(A, 3);

    Matrix <int> m (A, A);
    m.display();
    //std::vector<string> s { "\n", "\n", "\n", "s", "\n", "\n", "\n", "s"  };
    //for (auto& i : s) cout << i;
}
