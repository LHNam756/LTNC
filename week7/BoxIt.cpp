typedef long long ll;

class Box{
    public:
        Box():l(0),b(0),h(0){}
        Box(int _l, int _b, int _h):l(_l),b(_b),h(_h){}
        Box(const Box& _box):l(_box.l), b(_box.b), h(_box.h){}

        int getLength() const{return l;}
        int getBreadth()const{return b;}
        int getHeight() const{return h;}

        ll CalculateVolume(){
            ll v = ll(l)*ll(b)*ll(h);
            return v;
        }

        bool operator<( const Box& other ) const {
            if(l < other.l)
                return true;
            else if(b < other.b && l == other.l)
                return true;
            else if(h < other.h && l == other.l && b == other.b)
                return true;
        return false;
        }

        friend ostream& operator<< ( ostream& out, const Box box ){
        out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();
        return out;
        }
    private:
        int l;
        int b;
        int h;

};
