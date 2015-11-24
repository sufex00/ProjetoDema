#include"compression.h"
#include"decompression.h"

using namespace std;
int main(int argc, char *argv[])
{

    TreatmentHeader treatmentHeader = TreatmentHeader(argc, argv);
    compression Compression = compression();
    decompression Decompression = decompression();
    if(treatmentHeader.isCodificationComand())
    {

        if(treatmentHeader.isCodification())
        {
            Compression.operation(treatmentHeader);
        }
        else
        {
            Decompression.operation(treatmentHeader);
        }
    }
    else
        treatmentHeader.error();

    //huffdecotification teste=huffdecotification(QString("pedro"));

}
