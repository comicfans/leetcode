#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int64_t string2time(string str){

    int64_t year,month,day,hh,mm,ss;

    sscanf(str.c_str(),"%ld:%ld:%ld:%ld:%ld:%ld",&year,&month,&day,&hh,&mm,&ss);

    --month;
    --day;

    return 
        year*12*31*24*60*60+
        month*31*24*60*60+
        day*24*60*60+
        hh*60*60+
        mm*60+
        ss;
}

class LogSystem {
    public:

        map<int64_t,int> logs;

        LogSystem() {

        }

        void put(int id, string timestamp) {

            int64_t timeint=string2time(timestamp);

            logs[timeint]=id;

        }

        vector<int> retrieve(string s, string e, string gra) {

            int64_t beginint=string2time(s);
            int64_t endint=string2time(e);



            int64_t round;


            if (gra==string("Year")) {
                round=12*31*24*60*60;
            }else if(gra==string("Day")){
                round=24*60*60;
            }else if (gra==string("Hour")){
                round=60*60;
            }else if (gra==string("Second")){
                round=1;
            }else if (gra==string("Month")){
                round=31*24*60*60;
            }else if (gra==string("Minute")){
                round=60;
            }

            int64_t realbegin = (beginint/round)*round;
            int64_t realend= 
                    (endint/round)*round+round-1;



            map<int64_t,int>::const_iterator 
                beginPos=logs.lower_bound(realbegin),
                endPos=logs.upper_bound(realend);

            vector<int> result;

            for(map<int64_t,int>::const_iterator it=beginPos;it!=endPos;++it){
                
                result.push_back(it->second);
            }

            return result;
        }
};

/* *
 *  * Your LogSystem object will be instantiated and called as such:
 *   * LogSystem obj = new LogSystem();
 *    * obj.put(id,timestamp);
 *     * vector<int> param_2 = obj.retrieve(s,e,gra);
 *      */ 



int main(int argc, char *argv[])
{

    LogSystem obj1 ;
    obj1.put(1,"2017:01:01:23:59:59");
    obj1.put(2,"2017:01:02:23:59:59");

    vector<int> try1=obj1.retrieve(
            "2017:01:01:23:59:59",
            "2017:01:02:23:59:59",
            "Second"); // return (1,2)need to return all logs within 2016 and 2017.

    copy(try1.begin(),try1.end(),ostream_iterator<int>(cout,","));

    cout<<endl;

    LogSystem obj2 ;



    obj2.put(1,"2017:01:01:23:59:59");
    obj2.put(2,"2017:01:02:23:59:59");

    vector<int> try2=obj2.retrieve(
            "2017:01:01:23:59:58",
            "2017:01:02:23:59:58",
            "Second"
            ); // return (1)need to return all logs within 2016 and 2017.

    copy(try2.begin(),try2.end(),ostream_iterator<int>(cout,","));
    cout<<endl;


    LogSystem obj3;
    obj3.put(3,"2016:01:01:00:00:00");
    obj3.put(2,"2017:01:01:22:59:59");
    obj3.put(1,"2017:01:01:23:59:59");

    
    auto k3=obj3.retrieve("2016:01:01:01:01:01",
            "2017:01:01:23:00:00","Hour");
    //((),(),(2,"2017:01:01:22:59:59"),(),("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"),("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"))

    copy(k3.begin(),k3.end(),ostream_iterator<int>(cout,","));
    cout<<endl;


    LogSystem o4;
    o4.put(1,"2005:01:05:22:16:15");
    o4.put(2,"2003:12:12:20:30:51");
    o4.put(3,"2001:06:25:23:51:23");
    o4.put(4,"2004:10:25:13:49:48");
    o4.put(5,"2002:05:03:14:21:45");
    o4.put(6,"2004:10:04:21:49:49");


    o4.put(7,"2006:05:14:18:30:30");
    o4.put(8,"2003:04:02:22:12:41");
    o4.put(9,"2002:02:25:13:12:24");
    o4.put(10,"2005:01:17:23:36:39");
    o4.put(11,"2000:07:25:12:45:16");
    o4.put(12,"2001:08:12:16:35:55");
    o4.put(13,"2000:10:18:18:46:38");

    auto r4=o4.retrieve(
            "2004:09:23:19:31:46","2005:10:27:16:51:21","Year"
            );

    copy(r4.begin(),r4.end(),ostream_iterator<int>(cout,","));
    cout<<endl;
    return 0;
}
