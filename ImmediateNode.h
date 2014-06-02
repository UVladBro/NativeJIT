#pragma once

#include "Node.h"


namespace NativeJIT
{
    template <typename T>
    class ImmediateNode : public Node<T>
    {
    public:
        ImmediateNode(ExpressionTree& tree, T value);

        T GetValue() const;

        //
        // Overrides of Node methods
        //
        virtual void Print() const override;


        //
        // Overrrides of ValueNode methods
        //
        virtual Storage<T> CodeGenValue2(ExpressionTree& tree) override;

    private:
        T m_value;
    };


    //*************************************************************************
    //
    // RXXImmediateValue
    //
    //*************************************************************************
    template <typename T>
    ImmediateNode<T>::ImmediateNode(ExpressionTree& tree,
                         T value)
        : Node(tree),
          m_value(value)
    {
    }


    template <typename T>
    T ImmediateNode<T>::GetValue() const
    {
        return m_value;
    }


    template <typename T>
    void ImmediateNode<T>::Print() const
    {
        std::cout << "ImmediateNode id=" << GetId();
        std::cout << ", parents = " << GetParentCount();
        std::cout << ", value = " << m_value;
        std::cout << ", ";
        PrintRegisterAndCacheInfo();
    }


    template <typename T>
    typename Storage<T> ImmediateNode<T>::CodeGenValue2(ExpressionTree& tree)
    {
        return Storage<T>(tree, m_value);
    }
}