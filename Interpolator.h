class Interpolator
{

    public:
        Interpolator(double vMax, double aMax, double ts);
        void Interpolate(double startPos, double endPos);


    private:
        double c_ts;
        double c_vMax;
        double c_aMax;
        double c_startPos;
        double c_endPos;


};
