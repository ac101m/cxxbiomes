#ifndef CXXBIOMES_UTIL_BUFFER2D_HPP
#define CXXBIOMES_UTIL_BUFFER2D_HPP

namespace cxxbiomes::util {

    template <class T>
    class Buffer2D {
    private:
        unsigned const m_width;
        unsigned const m_height;
        std::vector<T> m_data;

    public:
        Buffer2D(unsigned const width, unsigned const height) :
                m_width(width),
                m_height(height),
                m_data(std::vector<T>(width * height))
        {}

        Buffer2D(unsigned const width, unsigned const height, T const init) :
                m_width(width),
                m_height(height),
                m_data(std::vector<T>(width * height, init))
        {}

        unsigned Width() { return m_width; }
        unsigned Height() { return m_height; }

        T& At(unsigned const x, unsigned const z) {
            return m_data[(z * m_width) + x];
        }

        void Put(unsigned const x, unsigned const z, T const value) {
            m_data[(z * m_width) + x] = value;
        }
    };

} // cxxb::util

#endif //CXXBIOMES_UTIL_BUFFER2D_HPP
