//
// Created by againstsky on 2024/9/23.
//

#ifndef SDSHDR_H
#define SDSHDR_H

namespace againstsky {
    namespace sedis {
        const int INIT_LEN = 10;

        class SdsHdr {
        public:
            explicit SdsHdr(): _len(0), _free(INIT_LEN), _data(new char[_free]) {
            };

            explicit SdsHdr(const char *str);

            explicit SdsHdr(const char *str, const int initlen);

            void resize(const int size);

            void add(const char *str);

            const char *c_str() { return _data; }
            int len() const { return _len; }
            int free() const { return _free; }
            int size() const;

            ~SdsHdr() {
                delete[] _data;
                _len = 0;
                _free = 0;
            };

        private:
            int _len;
            int _free;
            char *_data;
        };
    }
} // againstsky

#endif //SDSHDR_H
