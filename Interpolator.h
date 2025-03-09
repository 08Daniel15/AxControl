class Interpolator
{

    public:
        double startPos = 0.0;
        double endPos = 0.0;
        double deltaPos = 0.0;
        Interpolator(double c_startPos, double c_endPos);
        Interpolator(double c_startPos, double c_endPos, double c_deltaPos);
        

    private:
        double malsehen = 0.0;
        int counts = 0;


};