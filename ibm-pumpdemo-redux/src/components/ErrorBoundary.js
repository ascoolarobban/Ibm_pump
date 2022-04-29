import React, { Component } from 'react';

class ErrorBoundary extends Component {
    
    constructor(props) {
        super(props)

        this.state = {
            hasError: false
        }
    }

    static getDerivedStateFromError(error) {
        return {
            hasError: true
        }
    } 

    render() {
        if (this.state.hasError) {
            return <h3>Alas, something is not as you thought it would be, Neil.</h3>
        }
        return this.props.children
    }
}

export default ErrorBoundary