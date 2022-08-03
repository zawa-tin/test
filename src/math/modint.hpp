namespace zawa {

    template<long long mod>
    class modint {
    private:
        long long x;

    public:
        modint() : x(0) {}
        
        modint(long long x) : x((x % mod + mod) % mod) {}

        modint& operator+=(modint p) {
            x += p.x;
            if (x >= mod) x -= mod;
            return *this;
        }

        modint& operator-=(modint p) {
            x += mod - p.x;
            if (x >= mod) x -= mod;
            return *this;
        }

        modint& operator*=(modint p) {
            x = (1LL * x * p.x % mod);
            return *this;
        }

        modint& operator/=(modint p) {
            *this *= p.inv();
            return *this;
        }

        modint operator-() const {
            return modint(-x);
        }

        modint operator+(const modint& p) const {
            return modint(*this) += p;
        }

        modint operator-(const modint& p) const {
            return modint(*this) -= p;
        }

        modint operator*(const modint& p) const {
            return modint(*this) *= p;
        }

        modint operator/(const modint& p) const {
            return modint(*this) /= p;
        }

        long long val() {
            return x;
        }

        modint pow(long long p) {
            modint res(1), val(x);
            while(p) {
                if (p & 1) res *= val;
                val *= val;
                p >>= 1;
            }
            return res;
        }

        modint inv() {
            return pow(mod - 2);
        }
    };

}// namespace zawa
